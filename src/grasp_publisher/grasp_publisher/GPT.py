import sys

import io
from PIL import Image
from matplotlib import pyplot as plt

import openai
from .camera_capture import zed
from .Detic import demo
from .owl_vit import detect_grasp_name
from .point_cloud_grasp_sample import get_GraspSample
from . import ik

import rclpy
from rclpy.node import Node
from std_msgs.msg import String

from grasp_msg.msg import GraspMessage
from grasp_msg.msg import JointPos



def get_grasp_object(assistant_message):
    grasp_object = assistant_message.split('Here is your ')[1].split('.')[0].strip()
    print(f"(Grasp object: {grasp_object})")

    return grasp_object


def gpt_grasp_part(grasp_object):
    openai.api_key = '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'

    msg = {'role':'user', 
           'content': "If you want to pick up " + grasp_object + ", which part makes the most sense to grasp? Name one part, for example anser 'handle' not 'the handle of spoon'. If the grasp object fruit or vegetable is, the grasp part is the object itself, for example if grasp 'pepper' then anser 'pepper'."}
    result = openai.ChatCompletion.create(model='gpt-4', messages=[msg])      # gpt-3.5-turbo
    grasp_part = result.choices[0].message['content']
    print(f"(Grasp part: {grasp_part})")
    
    return grasp_part



def get_chatgpt_response(messages):
    try:
        response = openai.ChatCompletion.create(
            model ="gpt-4",
            messages = messages,
            max_tokens = 150
        )

        assistant_message = response.choices[0].message['content'].strip()    
        return assistant_message

    except Exception as e:
        return f"error: {str(e)}"


def gpt_dialogue(grasp_publisher):
    openai.api_key = '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'

    filepath = zed()                                                                           # 00000
    
    message = [
    {"role": "system", "content": """
        Task: You are AI and in a kitchen. I am Human and will ask you for help. I will tell you, the objects on the table. Generate answer for object search and grasp. 
        You need to answer Action and Response. Actions are classified into four categories: confirm, respond, refuse and grasp. In grasp action, the response always is "Here is your + object name".
        Hier is a prompt for the task below:
        Start: you can see egg, saucepan, knife, bell pepper on the table.
        Human: Hi
        AI: Action: <respond>
            Response: Hello! What can I do for you?
        Human: I want to make a meal and I need some vegatables.
        AI: Action:  <confirm>
            Response: I can see Bell pepper. Would you like me to bring it to you?
        Human: Sure
        AI: Action: <grasp>
            Response: Here is your bell pepper.
        Human: Give me the milk please, I'm so thirsty.
        AI: Action: <respond>
            Response: I'm sorry. I cannot see any milk on the table. 
        Human: OK, bring me the knife, my kid wants to play.
        AI: Action: <refuse>
            Response: I'm sorry, but it is not safe for a kid to play knives. May be we can find something else for fun.
        Human: You are right. I should keep him away from this. Thank you.
        AI: Action: <respond>
        Response:You are welcome. Call me any time when you need another help.
        """}
        ]
    response_1 = get_chatgpt_response(message)
    message.append({"role": "assistant", "content": response_1})
    # print(f"ChatGPT1: {response_1}")

    ### demo output ###
    exist_object_prompt = demo.detect_exist_objects()
    message.append({"role": "user", "content": exist_object_prompt})
    # print(f"ChatGPT: {exist_object_prompt}")

    response_2 = get_chatgpt_response(message)
    message.append({"role": "assistant", "content": response_2})
    # print(f"ChatGPT2: {response_2}")



    input("Type 'q' to end the conversation")
    while True:
        user_input = input("\nHuman: ")
        message.append({"role": "user", "content": user_input})
        if user_input.lower() == 'q':
            print("Conversation ended")
            break

        response = get_chatgpt_response(message)
        message.append({"role": "assistant", "content": response})
        print(f"{response}")
        
        if "<grasp>" in response:
            plt.close()
            
            grasp_object = get_grasp_object(response)
            grasp_part = gpt_grasp_part(grasp_object)
    
            crop = True
            original_padding_image, cx, cy, w, h, height, width = detect_grasp_name(grasp_object, crop)

            # crop = False
            # cx, cy, w, h = detect_grasp_name(grasp_part, crop, cx, cy, original_padding_image, height, width)
            
            q_buf = ik.ik(cx, cy, w, h)
            grasp_publisher.grasp_publish(q_buf)
    

            

class GraspPublisher(Node):

    def __init__(self):
        super().__init__('grasp_publisher')
        self.publisher_ = self.create_publisher(GraspMessage, 'grasp_position', 10)

    def grasp_publish(self, q_buf):
        msg = GraspMessage()
        for q in q_buf:
            pos = JointPos()
            for i in range(0,7):
                pos.joint_pos[i] = q[i]
            
            msg.q_buf.append(pos)
        # msg.q_buf = q_buf
        self.publisher_.publish(msg)

def main(args=None):
    rclpy.init(args=None)
    grasp_publisher = GraspPublisher()
    gpt_dialogue(grasp_publisher)
    rclpy.spin(grasp_publisher)


    grasp_publisher.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
    

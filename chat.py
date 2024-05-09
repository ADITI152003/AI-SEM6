import random
import re
from datetime import datetime

greetings = ['Hello!', 'Hi!', 'Hey there!', 'Greetings!', 'Nice to see you!']
goodbyes = ['Goodbye!', 'See you later!', 'Bye!', 'Take care!']
help_responses = ['How may I assist you?', 'What can I do for you?', 'How can I help?']
problem_responses = ['I\'m sorry to hear that. Can you please tell me more about the problem?', 'Let me see if I can help. What seems to be the issue?', 'I\'ll do my best to help you. What\'s the problem?']
thankyou_responses = ['You are welcome!', 'No problem!', 'It was my pleasure!', 'Glad to help!']
prescription_responses = ['To get a prescription, please visit your nearest pharmacy with a doctor\'s recommendation.', 'For prescriptions, you need to consult a doctor in person.', 'Prescriptions require a consultation with a healthcare professional.']
facility_info_responses = ['Our hospital provides a range of medical services including emergency care, surgery, and specialized treatments.', 'We offer various medical facilities such as diagnostic imaging, laboratory services, and pharmacy. How can I assist you further?', 'Our medical facility is equipped with state-of-the-art equipment and staffed with skilled healthcare professionals. What information are you looking for?']
exit_commands = ['exit', 'quit', 'stop', 'end']

# Compile regex patterns for matching
greeting_pattern = re.compile(r'hello|hi|hey', re.IGNORECASE)
goodbye_pattern = re.compile(r'bye|goodbye|see you', re.IGNORECASE)
help_pattern = re.compile(r'help|support', re.IGNORECASE)
problem_pattern = re.compile(r'problem|issue|error', re.IGNORECASE)
thankyou_pattern = re.compile(r'thank you|thanks|thankyou', re.IGNORECASE)
appointment_pattern = re.compile(r'appointment', re.IGNORECASE)
prescription_pattern = re.compile(r'prescription|medicine', re.IGNORECASE)
facility_info_pattern = re.compile(r'facility|information|services', re.IGNORECASE)
exit_pattern = re.compile(r'|'.join(exit_commands), re.IGNORECASE)

def schedule_appointment(day):
    return f'Thanks! Your appointment is scheduled for {day}.'

def chatbot():
    print('Hospital Chatbot: ' + random.choice(greetings))
    while True:
        user_input = input('User: ')
        if re.search(greeting_pattern, user_input):
            print('Hospital Chatbot: ' + random.choice(greetings))
        elif re.search(goodbye_pattern, user_input):
            print('Hospital Chatbot: ' + random.choice(goodbyes))
            break
        elif re.search(help_pattern, user_input):
            print('Hospital Chatbot: ' + random.choice(help_responses))
        elif re.search(problem_pattern, user_input):
            print('Hospital Chatbot: ' + random.choice(problem_responses))
        elif re.search(thankyou_pattern, user_input):
            print('Hospital Chatbot: ' + random.choice(thankyou_responses))
        elif re.search(appointment_pattern, user_input):
            print('Hospital Chatbot: When would you like to schedule the appointment?')
            day_input = input('User: ')
            print('Hospital Chatbot: ' + schedule_appointment(day_input))
        elif re.search(prescription_pattern, user_input):
            print('Hospital Chatbot: ' + random.choice(prescription_responses))
        elif re.search(facility_info_pattern, user_input):
            print('Hospital Chatbot: ' + random.choice(facility_info_responses))
        elif re.search(exit_pattern, user_input):
            print('Hospital Chatbot: ' + random.choice(goodbyes))
            break
        else:
            print('Hospital Chatbot: I\'m sorry, I don\'t understand. Can you please rephrase your request?')

chatbot()
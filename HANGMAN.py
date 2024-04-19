import random
import os
desktop_path = r'C:\Users\Samruddhi\Desktop\python projects'


file_path = os.path.join(desktop_path, "dictionary.txt")

# Open and read the external dictionary file
with open(file_path, 'r') as file:
    external_dictionary = [line.strip() for line in file]
    random_element = random.choice(external_dictionary)
logo = ''' 
 _                                             
| |                                            
| |__   __ _ _ __   __ _ _ __ ___   __ _ _ __  
| '_ \ / _` | '_ \ / _` | '_ ` _ \ / _` | '_ \ 
| | | | (_| | | | | (_| | | | | | | (_| | | | |
|_| |_|\__,_|_| |_|\__, |_| |_| |_|\__,_|_| |_|
                    __/ |                      
                   |___/    '''
print(logo)
stages = ['''
  +---+
  |   |
  O   |
 /|\  |
 / \  |
      |
=========
''', '''
  +---+
  |   |
  O   |
 /|\  |
 /    |
      |
=========
''', '''
  +---+
  |   |
  O   |
 /|\  |
      |
      |
=========
''', '''
  +---+
  |   |
  O   |
 /|   |
      |
      |
=========''', '''
  +---+
  |   |
  O   |
  |   |
      |
      |
=========
''', '''
  +---+
  |   |
  O   |
      |
      |
      |
=========
''', '''
  +---+
  |   |
      |
      |
      |
      |
=========
''']
lives=6
number=len(random_element)
display_blanks=[]
for _ in range(number):
    display_blanks.append("__")
print(display_blanks)
print()
element=display_blanks[0]
end_of_game=False
while not end_of_game:
  user_guess=input("ENTER YOUR GUESS:").lower()
  if user_guess in display_blanks:
     print("YOU HAVE ALREADY GUESSED THIS LETTER.")
  else:
        found = False
        for i in range(number):
            letter = random_element[i]
            if letter == user_guess:
                display_blanks[i] = letter
                found = True

        if found:
            print("YOUR GUESS IS RIGHT")
        else:
            print("YOUR GUESS IS WRONG, YOU LOSE A LIFE.")
            print(stages[lives - 1])
            lives -= 1
  print(display_blanks)
  if "__" not in display_blanks:
    end_of_game=True
    print("You win.")
  elif lives==0:
     end_of_game=True
     print("You lose")
     print(f"THE WORD WAS:{random_element}")


        
    

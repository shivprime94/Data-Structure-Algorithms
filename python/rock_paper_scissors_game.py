import random

player_1 = input("Enter your name:")
lives = 5
while True:
    player_1_move = input("Enter your move: ").rstrip()
    player_2_move = random.choice(["rock", "paper", "scissors"])
    state = ""

    '''
    Rock beats scissors
    paper beats rock
    scissors beat paper 
    '''

    if player_1_move == "rock" and player_2_move == "scissors":
        state = "win"
    elif player_1_move == "paper" and player_2_move == "rock":
        state = "win"
    elif player_1_move == "scissors" and player_2_move == "paper":
        state = "win"
    elif player_2_move == "rock" and player_1_move == "scissors":
        state = "loss"
    elif player_2_move == "paper" and player_1_move == "rock":
        state = "loss"
    elif player_2_move == "scissors" and player_1_move == "paper":
        state = "loss"

    if state == "win":
        print(f"You won {player_1}!")
    elif state != "win" and lives > 0:
        lives -= 1
        print("Computer won ::--))")
        print(f"{lives} lives remaining!")
    else:
        print("You lost all of your lives!!!")
        play_again = input("Press 'P' to continue or 'RETURN' to exit.")
        if not play_again.lower() == "p":
            print("Bye!!")
            break
        else:
            lives = 5




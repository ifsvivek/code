import random

def print_board(board):
    for i in range(3):
        print(' | '.join(board[i]))
        if i < 2:
            print('--------')

def check_win(board):
    for i in range(3):
        if board[i][0] == board[i][1] == board[i][2] != ' ' or board[0][i] == board[1][i] == board[2][i] != ' ':
            return True
    if board[0][0] == board[1][1] == board[2][2] != ' ' or board[0][2] == board[1][1] == board[2][0] != ' ':
        return True
    return False

def check_draw(board):
    for i in range(3):
        for j in range(3):
            if board[i][j] == ' ':
                return False
    return True

def make_move(board, player):
    while True:
        if player == 'human':
            row = int(input('Enter the row: '))
            col = int(input('Enter the column: '))
        else:
            row = random.randint(0, 2)
            col = random.randint(0, 2)
        if board[row][col] == ' ':
            board[row][col] = 'X' if player == 'human' else 'O'
            break

def play_game():
    board = [[' ']*3 for _ in range(3)]
    current_player = 'human'

    while True:
        print_board(board)
        make_move(board, current_player)
        if check_win(board):
            print(f'{current_player} wins!')
            break
        elif check_draw(board):
            print('The game is a draw.')
            break
        else:
            current_player = 'computer' if current_player == 'human' else 'human'

play_game()
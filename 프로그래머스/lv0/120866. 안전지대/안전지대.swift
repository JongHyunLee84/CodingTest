import Foundation

func solution(_ board:[[Int]]) -> Int {
    var boards = board
    var location : [[Int]] = []
    var firstIndex = 0
    var secondIndex = 0
    var result = 0

    if board.count == 1 && board[0][0] == 1 {
        return 0
    }
    
    for i in board {
        
        for j in i {
            
            if j == 1 {
                location.append([firstIndex, secondIndex])
             
            }
            secondIndex += 1
        }
        secondIndex = 0
        firstIndex += 1
    }

    for i in location {
        
        for j in i[0]-1...i[0]+1 {
            if j < 0 || j >= board.count {
                continue
            }
            for k in i[1]-1...i[1]+1 {
                if k < 0 || k >= board.count {
                    continue
                }
                boards[j][k] = 1
            }
        }
    }

    for i in boards {
        for j in i {
            if j == 0 {
                result += 1
            }
        }
    }
 
    return result
}
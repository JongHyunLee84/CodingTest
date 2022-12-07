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
   
    firstIndex = 0
    for i in location {
        for j in boards {
            var k = j
            if firstIndex == (i[0] - 1) {
                switch i[1] {
                case 0 :
                    if k[i[1]] == 0 {
                        k[i[1]] = 2
                    }
                    if k[i[1]+1] == 0 {
                        k[i[1]+1] = 2
                    }
                case board.count - 1 :
                    if k[i[1]] == 0 {
                        k[i[1]] = 2
                    }
                    if k[i[1]-1] == 0 {
                        k[i[1]-1] = 2
                    }
                default :
                    if k[i[1]] == 0 {
                        k[i[1]] = 2
                    }
                    if k[i[1]-1] == 0 {
                        k[i[1]-1] = 2
                    }
                    if k[i[1]+1] == 0 {
                        k[i[1]+1] = 2
                    }
                }

            }
            else if firstIndex == i[0] {
                switch i[1] {

                case 0 :
                    if k[i[1]] == 0 {
                        k[i[1]] = 2
                    }
                    if k[i[1]+1] == 0 {
                        k[i[1]+1] = 2
                    }
                case board.count - 1 :
                    if k[i[1]] == 0 {
                        k[i[1]] = 2
                    }
                    if k[i[1]-1] == 0 {
                        k[i[1]-1] = 2
                    }
                default :
                    if k[i[1]] == 0 {
                        k[i[1]] = 2
                    }
                    if k[i[1]-1] == 0 {
                        k[i[1]-1] = 2
                    }
                    if k[i[1]+1] == 0 {
                        k[i[1]+1] = 2
                    }
                }

            }
            else if firstIndex == (i[0] + 1) {
                switch i[1] {
                case 1...3 :
                    if k[i[1]] == 0 {
                        k[i[1]] = 2
                    }
                    if k[i[1]-1] == 0 {
                        k[i[1]-1] = 2
                    }
                    if k[i[1]+1] == 0 {
                        k[i[1]+1] = 2
                    }
                case 0 :
                    if k[i[1]] == 0 {
                        k[i[1]] = 2
                    }
                    if k[i[1]+1] == 0 {
                        k[i[1]+1] = 2
                    }
                case 4 :
                    if k[i[1]] == 0 {
                        k[i[1]] = 2
                    }
                    if k[i[1]-1] == 0 {
                        k[i[1]-1] = 2
                    }
                default :
                    break
                }

            }
            boards[firstIndex] = k
            firstIndex += 1
        }
        firstIndex = 0
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
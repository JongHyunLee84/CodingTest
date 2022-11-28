import Foundation


func solution(_ keyinput:[String], _ board:[Int]) -> [Int] {
    var x = 0
    var y = 0
    var maxX = (board[0]-1) / 2
    var maxY = (board[1]-1) / 2
    
    for i in keyinput {
        switch i {
            case "left":
            if x <= -maxX {
                continue
            }
            x -= 1
            case "right":
            if x >= maxX {
                continue
            }
            x += 1
            case "up":
            if y >= maxY {
                continue
            }
            y += 1
            case "down":
            if y <= -maxY {
                continue
            }
            y -= 1
            default:
            break
        }
    }

    return [x, y]
}

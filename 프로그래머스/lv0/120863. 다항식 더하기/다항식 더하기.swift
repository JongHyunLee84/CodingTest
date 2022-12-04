import Foundation

func solution(_ polynomial:String) -> String {
    var array = polynomial.components(separatedBy: " ")
    var countX = 0
    var countNum = 0
    for i in array {
        if i == "+" {
            continue
        }
        if i.last == "x" {
            if i.count == 1 {
                countX += 1
            } else {
                var isRemoved = i
                isRemoved.removeLast()
                countX += Int(isRemoved)!
            }
        } else {
            countNum += Int(i)!
        }
    }
    var result = ""
    switch (countX, countNum) {
    case (0,1...):
        result = "\(countNum)"
        case (1,0):
        result = "x"
        case (1,1...):
        result = "x + \(countNum)"
    case (2...,0):
        result = "\(countX)x"
    default:
        result = "\(countX)x + \(countNum)"

    }
    
    
    return result
}

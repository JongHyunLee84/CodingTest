import Foundation

func solution(_ sides:[Int]) -> Int {
    var side = sides.sorted()
    var result = 0
    
    
    for i in 1...side[1] {
        if i + side[0] > side[1] {
            result += 1
        }
    }
    for i in (side[1]+1)..<side[0]+side[1] {
        if i < side[0] + side[1] {
            result += 1
        } else {
            break
        }
    }
    return result 
}
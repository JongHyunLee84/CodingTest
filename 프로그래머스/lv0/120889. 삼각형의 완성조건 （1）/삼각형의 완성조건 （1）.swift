import Foundation

func solution(_ sides:[Int]) -> Int {
    var maxArray = sides.sorted()
    if maxArray[2] < maxArray[0] + maxArray[1] {
        return 1
    } else {
        return 2
    }
    
}
import Foundation

func solution(_ numbers:[Int], _ direction:String) -> [Int] {
    var result : [Int] = []
            if direction == "right" {
                result.append(numbers[numbers.count-1])
                for i in 0..<numbers.count-1 {
                    result.append(numbers[i])
                }
            } else if direction == "left" {
                for i in 1..<numbers.count {
                    result.append(numbers[i])
                }
                result.append(numbers[0])
            }
    return result
    
}
import Foundation


func solution(_ numbers:[Int], _ num1:Int, _ num2:Int) -> [Int] {
    var result: [Int] = []
    var index = num1
    for _ in 0...numbers.count {
        result.append(numbers[index])
        if index == num2 {
            return result
        }
        index += 1
    }
    return result
}

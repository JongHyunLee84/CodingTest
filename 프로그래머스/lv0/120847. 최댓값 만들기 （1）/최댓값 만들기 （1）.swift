import Foundation

func solution(_ numbers:[Int]) -> Int {
    var maxNum = 0
    var secondMaxNum = 0
    // 최댓값 두 개를 추출
    for i in numbers {
        if i > maxNum {
            maxNum = i
        }
    }
        var array: [Int] = numbers
    var maxIndex = array.firstIndex(of:maxNum) ?? 0
        array.remove(at: maxIndex)
        for i in array {
            if i > secondMaxNum {
                secondMaxNum = i
            }
        }
    // 두 수의 곱
    return maxNum*secondMaxNum
    }
    

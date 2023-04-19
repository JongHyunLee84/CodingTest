import Foundation

func solution(_ answers:[Int]) -> [Int] {
    var a = [1, 2, 3, 4, 5,1, 2, 3, 4, 5,1, 2, 3, 4, 5,1, 2, 3, 4, 5,1, 2, 3, 4, 5, 1, 2, 3, 4, 5,1, 2, 3, 4, 5,1, 2, 3, 4, 5]
    var b = [2, 1, 2, 3, 2, 4, 2, 5,2, 1, 2, 3, 2, 4, 2, 5,2, 1, 2, 3, 2, 4, 2, 5,2, 1, 2, 3, 2, 4, 2, 5,2, 1, 2, 3, 2, 4, 2, 5]
    var c = [3, 3, 1, 1, 2, 2, 4, 4, 5, 5,3, 3, 1, 1, 2, 2, 4, 4, 5, 5,3, 3, 1, 1, 2, 2, 4, 4, 5, 5,3, 3, 1, 1, 2, 2, 4, 4, 5, 5]
    var array: [Int:Int] = [1:0,2:0,3:0]
    for i in 0..<answers.count {
        if i < 40 {
            if answers[i] == a[i] {
                array[1]! += 1
            }
            if answers[i] == b[i] {
                array[2]! += 1
            }
            if answers[i] == c[i] {
                array[3]! += 1
            }
            
        } else {
            if answers[i] == a[i % 40] {
                array[1]! += 1
            }
            if answers[i] == b[i % 40] {
                array[2]! += 1
            }
            if answers[i] == c[i % 40] {
                array[3]! += 1
            }
        }
    }
    return array.keys.filter { array[$0] == array.values.max() }.sorted()
}
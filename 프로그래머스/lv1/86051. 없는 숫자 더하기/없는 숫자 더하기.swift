import Foundation

func solution(_ numbers:[Int]) -> Int {
    var array = [0,1,2,3,4,5,6,7,8,9]
    for i in numbers {
        array.remove(at: array.firstIndex(of: i)!)
    }
    return array.reduce(0, +)
}
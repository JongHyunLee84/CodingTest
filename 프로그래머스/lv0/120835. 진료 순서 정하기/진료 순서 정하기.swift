import Foundation

func solution(_ emergency:[Int]) -> [Int] {
    var array = emergency.sorted()
    var result : [Int] = []
    for i in emergency {
        result.append(emergency.count - array.firstIndex(of: i)!)
    }
    return result
}
import Foundation

func solution(_ numbers:[Int], _ target:Int) -> Int {
    var result = 0
    let totalCnt = numbers.count
    func recursion(_ idx: Int, _ sum: Int) {
        if idx == totalCnt {
            if sum == target {
                result += 1
            }
            return
        }
        recursion(idx+1, sum + numbers[idx])
        recursion(idx+1, sum - numbers[idx])
    }
    recursion(0, 0)
    return result
}
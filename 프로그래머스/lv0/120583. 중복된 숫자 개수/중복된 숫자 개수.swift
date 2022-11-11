import Foundation

func solution(_ array:[Int], _ n:Int) -> Int {
    var result = 0
    // 배열의 요소들과 n을 비교
    for i in array {
        if i == n {
            result += 1
        }
    }
    // n과 같을 때 갯수를 셈
    // 갯수를 리턴
    return result
}
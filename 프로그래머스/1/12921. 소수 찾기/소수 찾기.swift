import Foundation
func solution(_ n:Int) -> Int {
    if n == 2 { return 1 }
    var primeList = Array(repeating: 0, count: n + 1)
    primeList[0] = 1
    primeList[1] = 1
    // N = 100이라고 해봅시다. sqrt(100) = 10입니다.
    // 100의 인수들을 나열해보면: 1, 2, 4, 5, 10, 20, 25, 50, 100
    // 여기서 볼 수 있듯이, 10(sqrt(100)) 이하의 인수들만 검사해도 모든 합성수를 걸러낼 수 있습니다.
    let maxNum = Int(sqrt(Double(n)))
    for i in 2...maxNum {
        var temp = i * 2
        while temp <= n {
            primeList[temp] = 1
            temp += i
        }
    }
    return primeList.filter { $0 == 0 }.count
}

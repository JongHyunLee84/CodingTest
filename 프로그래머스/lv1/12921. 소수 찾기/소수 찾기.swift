import Foundation
func solution(_ n:Int) -> Int {
    if n == 2 {
        return 1
    }
    var array = Array(repeating: true, count: n+1)
    for i in 2...Int(sqrt(Double(n))+1) {
        if array[i] == true {
            var m = 2
            while i*m <= n {
                array[i*m] = false
                m += 1
            }
        }
    }
    let result = array.filter { $0 == true }.count
    return result - 2
}
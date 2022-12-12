
func solution(_ n:Int64) -> Int64 {
    var array = String(n).map { Int(String($0))! }.sorted(by: >)
    var result = Int64(array.map { String($0) }.joined())!
    return result
}

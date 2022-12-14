func solution(_ s:String) -> String {
    var count = s.count
    var result : [Character] = []
    var n = count / 2
    var array = Array(s)
    if count % 2 == 0 {
        result.append(array[n-1])
        result.append(array[n])
    } else {
        result.append(array[n])
    }
    return String(result)
}
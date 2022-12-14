func solution(_ s:String) -> Bool {
    var array = Array(s)
    if s.count > 6 || s.count < 4 || s.count == 5 {
        return false
    }
    for i in array {
        if !(i.isNumber) {
            return false
        }
    }
    return true
}
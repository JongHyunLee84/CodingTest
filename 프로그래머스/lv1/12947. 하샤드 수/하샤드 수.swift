func solution(_ x:Int) -> Bool {
    var num = 0 
    for i in String(x) {
        num += Int(String(i))!
    }
    return x % num == 0 ? true : false
}
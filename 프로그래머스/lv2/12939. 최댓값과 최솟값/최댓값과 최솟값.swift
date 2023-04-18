func solution(_ s:String) -> String {
    var a = s.split(separator: " ")
    var b = a.map { Int(String($0))! }.sorted()
    return "\(b[0]) \(b.last!)"
    
}
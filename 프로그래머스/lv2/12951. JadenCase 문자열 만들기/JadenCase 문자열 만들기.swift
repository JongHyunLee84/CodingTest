func solution(_ s: String) -> String {
    var a = s.components(separatedBy: " ")
    print(a)
    var result = ""
    for i in a {
        if i == "" {
            
        } else if i.first!.isLetter {
            result += i.capitalized
        } else {
            result += i.lowercased
        }
        if i == a.last! {
            break
        }
        result += " "
    }
    return result
}

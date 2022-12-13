func solution(_ phone_number:String) -> String {
    var result = ""
    var count = 0 
    for i in phone_number {
        if count < phone_number.count - 4 {
            result += "*"
        } else {
            result += "\(i)"
        }
        count += 1
    }
    return result
}
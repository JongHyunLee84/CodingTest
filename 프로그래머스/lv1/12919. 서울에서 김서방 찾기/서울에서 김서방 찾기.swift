func solution(_ seoul:[String]) -> String {
    var location = 0
    for i in seoul {
        if i == "Kim" {
            return "김서방은 \(location)에 있다"
        }
        location += 1
        
    }
    return "김서방은 \(location)에 있다"
}
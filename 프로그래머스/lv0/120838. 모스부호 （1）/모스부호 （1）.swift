import Foundation

func solution(_ letter:String) -> String {
    let array = letter.components(separatedBy: " ")
    let morse: [String:String] = [
        ".-":"a","-...":"b","-.-.":"c","-..":"d",".":"e","..-.":"f",
        "--.":"g","....":"h","..":"i",".---":"j","-.-":"k",".-..":"l",
        "--":"m","-.":"n","---":"o",".--.":"p","--.-":"q",".-.":"r",
        "...":"s","-":"t","..-":"u","...-":"v",".--":"w","-..-":"x",
        "-.--":"y","--..":"z"
    ]
    var result: [String] = []
    for i in array {
        result.append(morse[i]!)
    }
    
    
    return result.joined()
}

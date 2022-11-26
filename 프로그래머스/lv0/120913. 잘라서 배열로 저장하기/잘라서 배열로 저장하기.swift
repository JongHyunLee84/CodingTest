import Foundation

func solution(_ my_str:String, _ n:Int) -> [String] {
    var num = 0 
    var s = ""
    var a = Array<String>()
    for i in my_str {
        
        s += String(i)
        num += 1
        if num == n {
            a.append(s)
            s = ""
            num = 0
        }
    }
    if my_str.count % n != 0 {
        a.append(s)
    }
    return a
}
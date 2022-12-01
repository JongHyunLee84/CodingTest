import Foundation


func solution(_ n:Int) -> Int {
    var array : [Int] = []
    var num = 0
    let index = n - 1
    for _ in 1...130 {
        
        if num % 3 == 0 {
            num += 1
            if String(num).contains("3") {
                num += 1
            }
        }
        
        if String(num).contains("3") {
            num += 1
            continue
        }
       
        array.append(num)
        num += 1
    }
    return array[index]
}

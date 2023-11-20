import Foundation

func solution(_ n:Int) -> Int 
{
    var ret = 0
    var num = n
    
    while(num != 0) {
        ret += num % 2
        num /= 2
    }

    return ret
}
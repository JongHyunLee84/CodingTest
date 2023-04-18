import Foundation

func solution(_ n:Int) -> Int
{
    var numberOfOneOfN = String(n,radix:2).filter{ $0 == "1"}
    var keep = true
    var nextNum = n + 1
    while keep {
        if String(nextNum,radix:2).filter{ $0 == "1"} == numberOfOneOfN {
            return nextNum
        }
    nextNum += 1
    }
}
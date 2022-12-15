import Foundation

func solution(_ n:Int) -> Int {
    Int(String(n, radix: 3).reversed().map { String($0)}.joined(), radix: 3)!
}
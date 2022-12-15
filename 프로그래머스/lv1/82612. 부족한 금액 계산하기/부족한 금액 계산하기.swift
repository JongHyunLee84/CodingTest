import Foundation

func solution(_ price:Int, _ money:Int, _ count:Int) -> Int64{
    var total : Int64 = 0 
    for i in 0..<count {
        total += Int64(price) * Int64((i + 1))
    }
    print(total)
    return Int64(money) - total < 0 ? total - Int64(money) : 0
}
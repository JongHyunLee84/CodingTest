import Foundation

func solution(_ n:Int, _ k:Int) -> Int {
    var drink = k
    drink -= n / 10
    var sheep = n * 12000
    var drinkSum = drink * 2000
    var sum = 0
    sum = sheep + drinkSum
    
    return sum
}
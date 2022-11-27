import Foundation

func solution(_ balls:Int, _ share:Int) -> Int {
    if balls == share {
        return 1
    }
    
    var num = (balls - share) >= share ? balls - share + 1 : share + 1
    var n : Double = 1
    var s : Double = 1
    if balls - share >= share {
        for i in 1...share {
            s *= Double(i)
        }
        n = n / s
       
        for i in num...balls {
            n *= Double(i)
        }
        return Int(round(n))
    } else {
   
        for i in num...balls {
            n *= Double(i)
        }
        for i in 1...(balls-share) {
            n /= Double(i)
        }
        return Int(round(n))
    }
}

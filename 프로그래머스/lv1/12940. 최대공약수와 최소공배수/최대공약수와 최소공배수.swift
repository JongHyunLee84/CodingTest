func solution(_ n:Int, _ m:Int) -> [Int] {
    var d = 1
    var r = 0
     while d <= n {
         if n % d == 0 && m % d == 0 {
             r = d
         }
         d += 1
     }
     var j = (n * m) / r
    return [r,j]
}
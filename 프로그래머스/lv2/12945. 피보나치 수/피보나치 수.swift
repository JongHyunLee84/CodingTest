var array: [Int] = Array(repeating: 0, count: 100001)

func solution(_ n:Int) -> Int {
    if n == 1 || n == 2 {
        return 1
    }
    if array[n] != 0 {
        return array[n] % 1234567
    }
        array[n] = solution(n-1) + solution(n-2)
        return array[n] % 1234567
}
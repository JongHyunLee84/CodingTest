import Foundation 

func solution(_ s: String) -> Int {
    let chars = Array(s)
    let n = chars.count
    var dp = Array(repeating: Array(repeating: false, count: n), count: n)
    var maxLength = 1

    // 모든 단일 문자는 팰린드롬입니다.
    for i in 0..<n {
        dp[i][i] = true
    }

    // 연속하는 두 문자의 팰린드롬을 확인합니다.
    for i in 0..<n-1 {
        if chars[i] == chars[i + 1] {
            dp[i][i + 1] = true
            maxLength = 2
        }
    }

    // 길이가 3 이상인 팰린드롬을 찾습니다.
    if n >= 3 {
        for length in 3...n {
            for start in 0...n-length {
                let end = start + length - 1
                // 양 끝의 문자가 같고, 내부 문자열이 팰린드롬이라면
                if chars[start] == chars[end] && dp[start + 1][end - 1] {
                    dp[start][end] = true
                    maxLength = length
                }
            }
        }
    }

    return maxLength
}

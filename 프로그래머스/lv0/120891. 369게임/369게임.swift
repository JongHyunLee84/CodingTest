import Foundation

func solution(_ order:Int) -> Int {
    String(order).filter {["3","6","9"].contains($0)}.count
}

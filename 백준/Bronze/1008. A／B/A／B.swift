//
//  main.swift
//  CodingTestPractice
//
//  Created by 이종현 on 2023/07/29.
//

import Foundation

var a = readLine()!.split(separator: " ").map { Double(String($0))! }
print(a[0] / a[1])



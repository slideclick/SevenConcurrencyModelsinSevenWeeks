;---
; Excerpted from "Seven Concurrency Models in Seven Weeks",
; published by The Pragmatic Bookshelf.
; Copyrights apply to this code. It may not be used to create training material, 
; courses, books, articles, and the like. Contact us if you are in doubt.
; We make no guarantees that this code is fit for any purpose. 
; Visit http://www.pragmaticprogrammer.com/titles/pb7con for more book information.
;---
(ns sum.core
  (:require [clojure.core.reducers :as r]))

(defn recursive-sum [numbers]
  (if (empty? numbers)
    0
    (+ (first numbers) (recursive-sum (rest numbers)))))
    
(defn rcursive-sum [numbers]
  (loop [result 0, x numbers]
    (if (empty? x)
      result
      (recur (+ result (first x)) (rest x)))      
      )
      )

(defn reduce-sum [numbers]
  (reduce #(+ %1 %2) 0 numbers))

(defn sum [numbers]
  (reduce + numbers))

(defn apply-sum [numbers]
  (apply + numbers))

(defn parallel-sum [numbers]
  (r/fold + numbers))

  (defn sum-down-from [sum x]
  (if (pos? x)
    (recur (+ sum x) (dec x))
    sum))
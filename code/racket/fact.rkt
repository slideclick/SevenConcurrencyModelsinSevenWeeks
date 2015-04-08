
#lang racket
(require racket/trace)
;(factorial 100000000000) will out of memory
(define (factorial n)
  (if (= n 1)
      1
      (+ n (factorial (- n 1)))))
      
(define (2factorial n)
  (fact-iter 1 1 n))

(define (fact-iter product counter max-count)
  (if (> counter max-count)
      product
      (fact-iter (+ counter product)
                 (+ counter 1)
                 max-count)))      
;(trace       fact-iter)



                 
                 
                 (factorial 10)
                 (factorial 1000)
                 (2factorial 100000000000)
                 (factorial 100000000000)
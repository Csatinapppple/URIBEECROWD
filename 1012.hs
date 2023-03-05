import Text.Printf

areaTriangle :: (Double,Double) -> Double
areaTriangle (base,height) = base/2*height

areaCircle :: Double -> Double
areaCircle radius =  3.14159 * (radius * radius)

areaTrapezium :: (Double,Double,Double) -> Double
areaTrapezium (a,b,height) = (height *(a+b))/2

areaSqrNRec :: (Double,Double) -> Double
areaSqrNRec (width,height) = width*height

main :: IO()
main = do
  line <- getLine
  let (a:b:c:_) = map (read :: String -> Double) $ words line
  let (triangulo:circulo:trapezio:quadrado:retangulo:_) = [areaTriangle (a,c), areaCircle c, areaTrapezium (a,b,c),areaSqrNRec(b,b),areaSqrNRec(a,b)] 
  printf "TRIANGULO: %.3f\n" triangulo
  printf "CIRCULO: %.3f\n" circulo
  printf "TRAPEZIO: %.3f\n" trapezio
  printf "QUADRADO: %.3f\n" quadrado
  printf "RETANGULO: %.3f\n" retangulo

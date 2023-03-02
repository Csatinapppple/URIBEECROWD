main :: IO()
main = do
  let x = fmap (map read.words) getLine
  print x

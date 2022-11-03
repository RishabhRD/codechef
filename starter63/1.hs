module Main where
import           Control.Arrow ((>>>))
import           Data.List

solve :: (Num a, Enum a) => a -> [a]
solve n = [1..n]

readInt :: String -> Int
readInt = read

main :: IO ()
main = do
  interact $ lines
        >>>  drop 1
        >>>  fmap readInt
        >>>  fmap solve
        >>>  fmap (fmap show)
        >>>  fmap unwords
        >>>  unlines
  return ()

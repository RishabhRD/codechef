module Main where
import           Control.Arrow ((>>>))
import           Data.List

solve :: String -> Bool
solve "1" = True
solve s = solve' s
  where solve' = all even . fmap length . filter ((=='1') . head) . group

boolToString :: Bool -> String
boolToString True  = "Yes"
boolToString False = "No"

main :: IO ()
main = do
  interact $ lines
         >>> drop 1
         >>> zip [1..]
         >>> filter (even . fst)
         >>> fmap snd
         >>> fmap solve
         >>> fmap boolToString
         >>> unlines
  return ()

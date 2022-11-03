{-# LANGUAGE TupleSections #-}
module Main where

import           Control.Monad         (replicateM_)
import           Data.Bits             (Bits (clearBit))
import qualified Data.ByteString.Char8 as C
import           Data.IntMap
import           Data.List             (unfoldr)

solve :: Int -> [Int] -> Int
solve n xs = n - maximum (elems freqMap)
  where freqMap = fromListWith (+) $ (,1). (`clearBit` 0) <$> xs

readInt :: C.ByteString -> Int
readInt s = let Just (i,_) = C.readInt s in i :: Int

readInt2 :: C.ByteString -> (Int, Int)
readInt2 u = (a, b)
  where
  Just (a,v) = C.readInt u
  Just (b,_) = C.readInt (C.tail v)

readInts :: C.ByteString -> [Int]
readInts = unfoldr go where
    go s = do
        (n,s1) <- C.readInt s
        let s2 = C.dropWhile (==' ') s1
        pure (n,s2)

getInt :: IO Int
getInt  = readInt <$> C.getLine

getInt2 :: IO (Int, Int)
getInt2 = readInt2 <$> C.getLine

getInts :: IO [Int]
getInts = readInts <$> C.getLine

main :: IO ()
main = getInt >>= flip replicateM_ docase

docase :: IO ()
docase = do
    n <- getInt
    xs <- getInts
    print $ solve n xs

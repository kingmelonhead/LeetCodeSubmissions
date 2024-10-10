impl Solution {
    pub fn my_atoi(s: String) -> i32 { // string will be between 0 and 200 chars long
        
        let mut retValue: i64 = 0;
        let mut foundSign: bool = false;
        let mut numPositive: bool = true;
        let numPositiveRef = &mut numPositive;
        let mut tempNum: i64 = 0;
        let tempNumRef = &mut tempNum;

        for character in s.chars()
        {
            if !foundSign && Self::isSpace(character) // check for white space
            {
                // do nothing
            }
            else if !foundSign && Self::isSign(character, numPositiveRef)
            {
                foundSign = true;
            }
            else if Self::isValidDigit(character, tempNumRef)
            {
                foundSign = true;
                retValue = (retValue * 10) + *tempNumRef;
            }
            else
            {
                break;
            }
        }

        // Apply sign
        if !numPositive
        {
            retValue *= -1;
        }

        // Do rounding
        if retValue > i32::MAX as i64
        {
            retValue = i32::MAX as i64;
        }
        else if retValue < i32::MIN as i64
        {
            retValue = i32::MIN as i64;
        }
        return retValue as i32;
    }

    pub fn isSign(c: char, positive: &mut bool) -> bool
    {
        let mut retVal: bool = true;
        if c as u8 == 0x2B // + sign
        {
            *positive = true;
        }
        else if c as u8 == 0x2D // - sign
        {
            *positive = false;
        }
        else
        {
            retVal = false;
        }
        return retVal;
    }

    pub fn isValidDigit(c: char, digit: &mut i64) -> bool
    {
        let mut valid: bool = false;
        if c as u8 >= 0x30 && c as u8 <= 0x39
        {
            valid = true;
            *digit = c as i64 - 0x30;
        }
        return valid;
    }

    pub fn isSpace(c: char) -> bool 
    {
        return c as u8 == 0x20; // space
    }
}
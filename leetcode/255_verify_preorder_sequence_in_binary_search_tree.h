/* FAV!! Use Stack ,use it self as stack*/
bool verifyPreorder(int* preorder, int preorderSize)
{
    if (!preorder || !preorderSize)
        return true;

    int min = INT_MIN;
    int si = 0;
    for (int i = 0; i < preorderSize; i ++)
    {
        int x = preorder[i];

        if (!si)
            preorder[si ++] = x;
        else
        {
            if (x < min)
                return false;

            if (x < preorder[si - 1])
                preorder[si ++] = x;
            else
            {
                min = preorder[si - 1];
                si --;
                i --;
            }
        }
    }
    return true;
}

/* Fast Time wrong answer !!! */
/* Fast Time ? TOOOOOOO SLOW AGAIN !!!!! */
/* because si is not used as stack !!!! */

/*
  bool verifyPreorder(int* preorder, int preorderSize)
  {
  if (!preorder || !preorderSize)
  return true;

  int min = INT_MIN;
  int si = 0;
  for (int i = 0; i < preorderSize; i ++)
  {
  int x = preorder[i];
  if (!si)
  si = i + 1;
  else
  {
  if (x < min)
  return false;

  if (x < preorder[si - 1])
  si ++;
  else
  {
  if (min < preorder[si - 1])
  min = preorder[si - 1];
  si --;
  i --;
  }
  }
  }
  return true;
  }
*/
/* constant space */
/*
  bool verifyPreorder(int* preorder, int preorderSize)
  {
  if (!preorder || !preorderSize)
  return true;
  for (int i = 0; i < preorderSize - 1; i ++)
  {
  int x = preorder[i];
  if (preorder[i + 1] < x)
  {
  int j = i + 1;
  while(j < preorderSize && preorder[j] < x)
  {
  preorder[j - 1] = preorder[j];
  j ++;
  }
  preorder[-- j] = x;
  i --;
  }
  }

  for (int i = 0; i < preorderSize - 1; i ++)
  if (preorder[i + 1] < preorder[i])
  return false;
  return true;
  }
*/

#include <Python.h>

PyObject* wrap_btod(PyObject* self, PyObject* args) 
{
    int result;
    char *n;

    if (! PyArg_ParseTuple(args, "s:btod", &n))
        return NULL;

    result = btod(n);
    return Py_BuildValue("i", result);
}

PyObject* wrap_dtob(PyObject* self, PyObject* args) 
{
  int n, count, result;
  char *bstr;
  
  if (! PyArg_ParseTuple(args, "iis:dtob", &n, &count, &bstr))
    return NULL;
  result = dtob(n, count, bstr);
  return Py_BuildValue("i", result);
}

static PyMethodDef math_binMethods[] = 
{
    {"btod", wrap_btod, METH_VARARGS, "btod"},
    {"dtob", wrap_dtob, METH_VARARGS, "dtob"},
    {NULL, NULL}
};
void initmath_bin() 
{
    PyObject* m;
    m = Py_InitModule("math_bin", math_binMethods);
}


# uvicorn back:app --reload --host 0.0.0.0 --port 7965
import uvicorn

if __name__ == "__main__":
  uvicorn.run("server:app", host="0.0.0.0", port=8000, reload=True)
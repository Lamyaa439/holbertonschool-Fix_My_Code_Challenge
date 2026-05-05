#!/usr/bin/python3
"""
 User Model
"""
import hashlib
import uuid


class User():
    """
    User class:
    - id: public string unique (uuid)
    - password: private string hash in MD5
    """

    __password = None

    def __init__(self):
        """
        Initialize a new user
        """
        self.id = str(uuid.uuid4())

    @property
    def password(self):
        """
        Password getter
        """
        return self.__password

    @password.setter
    def password(self, pwd):
        """
        Password setter
        """
        if pwd is None or type(pwd) is not str:
            self.__password = None
        else:
            # Must be __password (double underscore)
            # Must be .lower()
            self.__password = hashlib.md5(pwd.encode()).hexdigest().lower()

    def is_valid_password(self, pwd):
        """
        Valid password comparison
        """
        if pwd is None or type(pwd) is not str:
            return False
        if self.__password is None:
            return False
        
        # Must match the setter (.lower())
        return hashlib.md5(pwd.encode()).hexdigest().lower() == self.__password


if __name__ == '__main__':
    user_1 = User()
    u_pwd = "myPassword"
    user_1.password = u_pwd

    if not user_1.is_valid_password(u_pwd):
        print("is_valid_password should return True if it's the right password")
